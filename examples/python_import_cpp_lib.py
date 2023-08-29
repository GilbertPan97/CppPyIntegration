from utils import WrapperLib

# Create WrapperLib objection
cppLib = WrapperLib.PyWrapperLib()

# Call capture_photo function
cppLib.capture_photo()

# Call process_image function
result_int, result_floats = cppLib.process_image()
print("Result int:", result_int)
print("Result floats:", result_floats)