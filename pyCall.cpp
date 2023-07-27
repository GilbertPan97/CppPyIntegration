#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <glog/logging.h>
#include <filesystem>           // For creating directories

using json = nlohmann::json;

struct BoxData {
    int numBoxes;
    std::vector<float> boxAngles;
};

// Function to simulate C++ program calculations and return box count and box angles
BoxData processBoxes() {
    BoxData data;
    data.numBoxes = 5;
    data.boxAngles = {45.5f, 30.0f, 60.2f, 90.8f, 120.1f};
    return data;
}

int main(int argc, char* argv[]) {
    // Initialize glog
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_prefix = false;      // Empty prefix
    FLAGS_logtostderr = true;      // Enable logging to console
    FLAGS_log_dir = "./logs";      // Set the log file output directory to the current directory

    // Create the "logs" directory if it doesn't exist
    std::filesystem::create_directory(FLAGS_log_dir);

    // Simulate data processing and get the result
    BoxData result = processBoxes();
    
    // // Specify the log filename (log.INFO in this case)
    // google::SetLogDestination(google::GLOG_INFO, "log.INFO");

    // Use the nlohmann/json library to construct JSON-formatted output
    json output;
    output["num_boxes"] = result.numBoxes;
    output["box_angles"] = result.boxAngles;

    // Output the result to the log file
    LOG(INFO) << output.dump(4);    // Use dump function to output in an indented format

    // Shutdown glog
    google::ShutdownGoogleLogging();

    return 0;
}
