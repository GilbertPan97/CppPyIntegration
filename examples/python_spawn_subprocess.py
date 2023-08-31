import json
import sys
import subprocess
import threading
import select
import time


def read_log_file(log_file):
    try:
        with open(log_file, 'r') as file:
            data = json.load(file)
            num_boxes = data.get('num_boxes', 0)
            box_angles = data.get('box_angles', [])
            return num_boxes, box_angles

    except Exception as e:
        print(f"Error reading log file: {e}")
        return None, None


def send_trigger_signal(proc):
    # Communicate with cpp, trigger to work once
    if proc.poll() is None:
        trigger_signal = True
        proc.stdin.write(str(trigger_signal) + '\n')
        proc.stdin.flush()


def rece_stderr_pipe(proc):
    std_content = ''

    # Skip error string of stderr
    line = proc.stderr.readline()
    while not line=='BeginData\n':
        line = proc.stderr.readline()
    
    # Read data after parse str=BeginData
    for line in proc.stderr:
        if not line=='EndData\n':
            std_content += line
        else:
            break
    return std_content


if __name__ == "__main__":
    # Log file and exec proc saved path
    log_file = "./logs/log.INFO"
    if sys.platform.startswith('win'):
        exec_file = "./bin/Release/py_subprocess"
    elif sys.platform.startswith('linux'):
        exec_file = "./bin/py_subprocess"

    # Execute C++ program and redirect output to a log file
    proc = subprocess.Popen([exec_file], stdin=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Work loop
    for i in range(5):
        # Communicate with cpp, trigger to work once
        send_trigger_signal(proc)
        
        # Receive data from stderr pipe
        str_result = rece_stderr_pipe(proc)

        # Write program return to log file
        with open(log_file, "w") as file:
            file.write(str_result)

    num_boxes, box_angles = read_log_file(log_file)

    if num_boxes is not None and box_angles is not None:
        print("INFO: Number of boxes: ", num_boxes)
        print("INFO: Angles of boxes: ", box_angles)
    
    proc.terminate()
