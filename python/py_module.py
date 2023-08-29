import socket
import pickle


def process_and_send_data(num_boxes, angles):
    # Implement your data processing logic here; for now, we simply print the received data
    print("Received number of boxes:", num_boxes)
    print("Received box angles:", angles)

    # Simulate a simple reply
    response_data = "Data received successfully!"
    return response_data


def main():
    # Fake data for testing
    num_boxes = 5
    angles = [45.5, 30.0, 60.2, 90.8, 120.1]

    # Call the data processing function
    response = process_and_send_data(num_boxes, angles)

    # Print the response result
    print("Response from process_and_send_data:", response)


if __name__ == "__main__":
    main()
