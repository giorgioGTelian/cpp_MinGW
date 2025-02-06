# cpp_MinGW
a c++ study using MinGW

GitHub Codespaces provides a cloud-based development environment that you can customize to suit your needs. To install and use **MinGW** in GitHub Codespaces, you need to configure the environment to include the necessary tools for C++ development. Here's how you can do it:

---

### Step 1: Create a GitHub Codespace
1. Go to your GitHub repository.
2. Click the **Code** button and select **Open with Codespaces**.
3. Create a new Codespace (or use an existing one).

---

### Step 2: Install MinGW in Codespaces
GitHub Codespaces uses Ubuntu as its base image, so you can install MinGW using `apt`, the package manager for Ubuntu.

1. Open the terminal in your Codespace.
2. Update the package list:
   ```bash
   sudo apt update
   ```
3. Install the MinGW compiler for C++:
   ```bash
   sudo apt install make wget tar zstd gpg

    git clone https://github.com/HolyBlackCat/quasi-msys2
    cd quasi-msys2/
    make install _gtk4   # equivalent to `make install mingw-w64-x86_64-gtk4`
   ```
    This downloads GTK4 to the current directory (./root/mingw64/) for you to use.

    But there's a problem: MinGW comes in different flavors, and the flavors provided by MSYS2 may or may not be compatible with the flavor provided by Ubuntu.

    The recommended build method doesn't depend on external MinGW. Instead I suggest using Clang, which can work with any MinGW flavor, if provided the right libraries (which we download from MSYS2).

    ```bash
    sudo apt install wine   # Optional.

    # Install latest Clang
    wget https://apt.llvm.org/llvm.sh
    chmod +x llvm.sh
    sudo ./llvm.sh
    rm llvm.sh

    # Install more packages
    make install _gcc _gdb    # We won't be using GCC, but we need libraries that come with it.

    # Opens a new shell with the right environment variables configured.
    env/shell.sh
    ```

4. Verify the installation:
   ```bash
   x86_64-w64-mingw32-g++ --version
   ```
   You should see output confirming the version of the MinGW compiler.

---

### Step 3: Write and Compile a C++ Program
1. Create a new C++ file in your Codespace, e.g., `test.cpp`:
   ```cpp
   #include <iostream>

   int main() {
       std::cout << "Hello, MinGW in GitHub Codespaces!" << std::endl;
       return 0;
   }
   ```

2. Compile the program using the MinGW compiler:
   ```bash
   x86_64-w64-mingw32-g++ -o test.exe test.cpp
   ```

3. Run the compiled program:
   ```bash
   wine test.exe
   ```
   Since Codespaces runs on Linux, you need **Wine** to run Windows executables. Install Wine if it's not already installed:
   ```bash
   sudo apt install wine
   ```

---

### Step 4: Automate Setup with a Dev Container (Optional)
To make MinGW available in every new Codespace, you can configure a **Dev Container** for your repository.

1. In your repository, create a `.devcontainer` directory.
2. Inside the `.devcontainer` directory, create a `Dockerfile`:
   ```Dockerfile
   FROM mcr.microsoft.com/devcontainers/base:ubuntu

   # Install MinGW
   RUN apt update && apt install -y mingw-w64 wine
   ```

3. Create a `devcontainer.json` file in the same directory:
   ```json
   {
     "name": "MinGW Development Environment",
     "build": {
       "dockerfile": "Dockerfile"
     },
     "postCreateCommand": "echo 'MinGW and Wine are installed!'"
   }
   ```

4. Commit and push these files to your repository.
5. The next time you create a Codespace, it will automatically install MinGW and Wine.

---

### Step 5: Test the Setup
1. Open a new Codespace.
2. Verify that MinGW is installed:
   ```bash
   x86_64-w64-mingw32-g++ --version
   ```
3. Write, compile, and run a C++ program as described in Step 3.

---

### Notes
- GitHub Codespaces is a Linux environment, so you cannot natively run Windows executables. Use **Wine** to run `.exe` files compiled with MinGW.
- If you don't need Windows-specific compilation, you can use the native `g++` compiler (installed by default in Codespaces) for Linux-based C++ development.

By following these steps, you can set up and use MinGW in GitHub Codespaces for C++ development!