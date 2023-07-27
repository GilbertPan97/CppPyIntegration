# socket_server.py

import socket
import pickle


def process_and_send_data(num_boxes, angles):
    # 在这里编写你的数据处理逻辑，这里我们仅简单地将数据打印出来
    print("Received number of boxes:", num_boxes)
    print("Received box angles:", angles)

    # 在这里实现socket通信逻辑，这里我们仅模拟一个简单的回复
    response_data = "Data received successfully!"
    return response_data


def main():
    # 用于测试的假数据
    num_boxes = 5
    angles = [45.5, 30.0, 60.2, 90.8, 120.1]

    # 调用数据处理函数
    response = process_and_send_data(num_boxes, angles)

    # 打印返回结果
    print("Response from process_and_send_data:", response)


if __name__ == "__main__":
    main()
