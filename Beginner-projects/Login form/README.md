# README for Registration and Login Page using C++

## Overview
This C++ program implements a simple registration and login system with features such as user sign-up, login, and password recovery. It utilizes file handling to store user records in a text file.

## Files
- **main.cpp**: Contains the main program logic with functions for login, sign-up, and password recovery.
- **records.txt**: Text file to store user records (username, email, and password).

## How to Use
1. Compile the program using a C++ compiler (e.g., g++).
   ```bash
   g++ main.cpp -o registration_login
   ```
2. Run the executable.
   ```bash
   ./registration_login
   ```
3. Follow the on-screen prompts to navigate through the main menu:
   - Press `1` for Login
   - Press `2` for Sign-up
   - Press `3` for Forgot Password
   - Press `4` to Exit

## Features
- **Login**: Validates the username and password against stored records.
- **Sign-up**: Checks for existing usernames or emails before allowing registration.
- **Forgot Password**: Allows users to recover passwords using either username or email.

## Notes
- User records are stored in the `records.txt` file in the format: `username*email*password`.

## Contributing
Feel free to contribute to the project by suggesting improvements or reporting issues. Fork the repository, make changes, and submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments
- The program was created by NOBODY1819.
- Special thanks to contributors and open-source projects that inspired or provided guidance.

For more details, refer to the source code and documentation within the files.
