# Union Encrypt
Note: This project is Windows OS specific

Welcome to Union Encrypt, a Python tool designed for text encryption and decryption using image encoding. This project simplifies the process of securing and revealing messages through images.
This algorithm can be used to encode text into images and decode images back to text.

## Table of Contents
- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
  - [Encrypt](#encrypt)
  - [Decrypt](#decrypt)

## Introduction<a name="introduction"></a>

Union Encrypt leverages Python and various modules, including subprocess, numpy, struct, and Pillow, to provide a secure way of encoding and decoding messages within images.

## Getting Started<a name="getting-started"></a>

To use Union Encrypt, follow these steps:
1. Before using Union Encrypt, ensure that you meet these prerequisites:
   - Python Interpreter
   - C Compiler
2. Clone the Union Encrypt repository to your local machine:

    ```bash
    git clone https://github.com/your-username/UnionEncrypt.git
    cd UnionEncrypt
    ```

3. Ensure you have the required modules installed:
   - Numpy:
     ```bash
     pip install numpy
     ```
   - Pillow (PIL):
     ```bash
     pip install pillow
     ```

4. Run the main file:

    ```bash
    python main.py
    ```

## Usage<a name="usage"></a>

### Encrypt<a name="encrypt"></a>

1. Ensure the text/message is written in the `text_input` file.
2. Select option 1 for encryption.
3. Provide a name for the image (without an extension).
4. You'll have an image with the name you provided in the same directory

### Decrypt<a name="decrypt"></a>

1. Select option 2 for decryption.
2. Place the image in the same folder.
3. Enter the name of the image with the extension (only valid encrypted image).
4. You'll get the decoded text/message in the `text_output` file.

Feel free to explore Union Encrypt and safeguard your messages with this image encoding tool. If you encounter any issues or have suggestions for improvements, please don't hesitate to reach out.
