import subprocess
import numpy as np
import struct
from PIL import Image


class Cryptography:
    def __init__(self, choice):
        self.choice = choice
        self.c_file_name = "encrypt.c" if choice == 1 else "decrypt.c"
        self.compile_command = f"gcc {self.c_file_name} -o {self.c_file_name}.exe"
        self.run_command = f".\\{self.c_file_name}.exe"
        self.text_output_file = "text_output.txt"
        self.num_input_file = "num_ip.txt"
        self.num_output_file = "num_op.txt"
        
    def encrypt(self, image_file):
        print("Encrypt", self.c_file_name)
        if self.runFile() == -1:
            return -1

        with open(self.num_output_file, 'r') as file:
            numbers = [int(line.strip()) for line in file]
        numbers = np.array(numbers, dtype=np.int32)

        image_pixels = [[]]
        for i in range(len(numbers)):
            if len(image_pixels[-1]) == 16:
                image_pixels.append([])
            byte_data = list(struct.pack('<i', numbers[i]))

            for pixel in byte_data:
                image_pixels[-1].append(pixel)

        max_len = max(len(row) for row in image_pixels)
        image_pixels = [row + [0] * (max_len - len(row)) for row in image_pixels]
        image_pixels = np.array(image_pixels, dtype=np.uint8)
        image_pixels = image_pixels.reshape((len(image_pixels), 16))

        image = Image.fromarray(image_pixels, 'L')
        image.save(f"{image_file}.png")

        print("Successful")

    def decrypt(self, image_file):
        print("Decrypt", self.c_file_name)

        image = Image.open(image_file)
        image_pixel = np.array(image)

        with open(self.num_input_file, 'w') as file:
            for pixels in image_pixel:
                for i in range(0, len(pixels), 4):
                    curr_num = bytes(pixels[i:i + 4])
                    curr_num = struct.unpack('<i', curr_num)[0]
                    if curr_num != 0:
                        file.write(str(curr_num) + '\n')

        return self.runFile()

    def runFile(self):
        compile_successful = subprocess.run(self.compile_command, shell=True)

        if compile_successful.returncode != 0:
            print("Compilation failed")
            return -1

        run_file = subprocess.run(self.run_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if run_file.returncode != 0:
            print("Terminated")
            return -1

        return 0


if __name__ == '__main__':
    print("1.Encrypt   2.Decrypt")
    choice = int(input("Enter your choice - "))
    embedded = Cryptography(choice)

    success = -1
    if choice == 1:
        success = embedded.encrypt(input("Enter image file name to save (without  .png)- "))
    elif choice == 2:
        success = embedded.decrypt(input("Enter image file - "))

    print("Done") if success != -1 else print("Failed")
