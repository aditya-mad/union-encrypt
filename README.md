# union-encrypt
Union Encrypt
Union Encrypt is a Python tool that allows you to encrypt and decrypt messages using image encoding. This project utilizes the subprocess, numpy, struct, and PIL (Python Imaging Library) modules.

Prerequisites
Before using Union Encrypt, ensure that you have the following installed:

Python interpreter
C compiler
Required Python modules: subprocess, numpy, struct, PIL
You can install the necessary Python modules using the following command:

bash
Copy code
pip install numpy struct pil
Usage
Clone the Union Encrypt repository to your local machine:
bash
Copy code
git clone https://github.com/your-username/UnionEncrypt.git
cd UnionEncrypt
Run the main file:
bash
Copy code
python main.py
Choose between the following options:
Encrypt (1): To encrypt a message and generate an encoded image.
Decrypt (2): To decode an image and retrieve the original message.
Encrypt
After choosing option 1, you will be prompted to enter the name for the image (without an extension).
Ensure that the text or message you want to encrypt is written in the text_input file.
Run the encryption process, and the tool will generate an image containing the encoded text.
Decrypt
If you choose option 2, place the image you want to decode in the same folder as the script.
Enter the name of the image with its extension.
The tool will decode the image and save the decrypted message in the text_output file.
