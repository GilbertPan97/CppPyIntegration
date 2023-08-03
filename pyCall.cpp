#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <glog/logging.h>
#include <filesystem>           // For creating directories
#include <chrono>   // For sleep function
#include <thread>   // For this_thread namespace

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
    FLAGS_logtostderr = true;      // Enable logging to console, (log write will be closed)
    FLAGS_log_dir = "./logs";      // Set the log file output directory to the current directory

    // Create the "logs" directory if it doesn't exist
    std::filesystem::create_directory(FLAGS_log_dir);

    // Simulate data processing and get the result
    BoxData result = processBoxes();
    
    // // Specify the log filename (log.INFO in this case)
    // google::SetLogDestination(google::GLOG_INFO, "log.INFO");

    while(true)
    {
        // Read trigger signal from Python
        std::string trigger_signal_str;
        std::getline(std::cin, trigger_signal_str);
        
        bool trigger_signal = (trigger_signal_str == "True");
        std::cout << "INFO: Program trigger status: working...\n";

        if(trigger_signal)
        {
            // Program work once, trigger_signal_str change to false
            std::cout << "INFO: Program trigger status (work once): " 
                      << trigger_signal_str << std::endl;

            // Use the nlohmann/json library to construct JSON-formatted output
            json output;
            output["num_boxes"] = result.numBoxes;
            output["box_angles"] = result.boxAngles;

            // Use dump function to output in an indented format
            LOG(INFO) <<"BeginData\n" << output.dump(4) 
                      << std::endl << "EndData\n";
        }
        
        // Sleep for a while to avoid high CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Shutdown glog
    google::ShutdownGoogleLogging();

    return 0;
}
