from utils import BinderLib

# Create BinderLib objection
binder = BinderLib.BinderLib()

# Call capture_photo function
binder.capture_photo()

# Call process_image function
result_int, result_floats = binder.process_image()
print("Result int:", result_int)
print("Result floats:", result_floats)