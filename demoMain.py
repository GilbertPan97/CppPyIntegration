import json
import subprocess


def read_log_file(log_file):
    try:
        with open(log_file, 'r') as file:
            data = json.load(file)
            num_boxes = data.get('num_boxes', 0)
            box_angles = data.get('box_angles', [])
            return num_boxes, box_angles

    except Exception as e:
        print(f"读取日志文件出现异常：{e}")
        return None, None


if __name__ == "__main__":
    log_file = "./logs/log.INFO"  # 此处的日志文件名与C++程序中的FLAGS_log_dir相对应
    # 执行C++程序并重定向输出到日志文件
    result = subprocess.run(["./bin/Debug/BaslerInfer"],  stderr=subprocess.PIPE, text=True)

    # 将C++程序的输出写入日志文件
    with open(log_file, "w") as file:
        file.write(result.stderr)

    num_boxes, box_angles = read_log_file(log_file)

    if num_boxes is not None and box_angles is not None:
        print("箱子数量：", num_boxes)
        print("箱子倾角：", box_angles)
