# Cipher
This is a concise, descriptive text suitable for the "About" section of your GitHub, GitLab, or Bitbucket repository:  Simple Substitution Cipher CLI tool written in C. Features dynamic key generation, basic message encryption/decryption, and a terminal-based menu interface.


# C-Cipher-Tool

A lightweight, console-based substitution cipher application written in C. This program allows users to encrypt and decrypt messages using a randomly generated mapping key.

## Features
* **Dynamic Key Generation:** Uses the `rand()` function with `srand()` to create a unique substitution key every time the program starts or is requested.
* **Encryption/Decryption:** Securely maps input text to a randomized character set while preserving characters not found in the mapping array (like spaces).
* **Menu-Driven Interface:** Simple, easy-to-navigate command-line interface for performing operations.

## Prerequisites
* **Compiler:** A C compiler (e.g., GCC).
* **OS:** This application utilizes the `<windows.h>` library for the `Sleep()` function. Therefore, it is designed to run natively on Windows environments.

## How to Compile and Run

1. **Clone the repository:**
   ```bash
   git clone <your-repository-url>
   cd <your-repository-directory>
