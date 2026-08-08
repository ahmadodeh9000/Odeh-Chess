import urllib.request
import zipfile
import os
import shutil

url = "https://github.com/libsdl-org/SDL/releases/download/release-2.28.5/SDL2-devel-2.28.5-mingw.zip"
zip_path = "SDL2-devel.zip"

print("Downloading SDL2 development libraries (2.28.5)...")
urllib.request.urlretrieve(url, zip_path)

print("Extracting...")
with zipfile.ZipFile(zip_path, 'r') as zip_ref:
    zip_ref.extractall(".")

print("Setting up headers and libraries...")
src_include = os.path.join("SDL2-2.28.5", "x86_64-w64-mingw32", "include", "SDL2")
dest_include = os.path.join("include", "SDL2")
if not os.path.exists(dest_include):
    os.makedirs(dest_include)

for f in os.listdir(src_include):
    shutil.copy2(os.path.join(src_include, f), dest_include)

src_lib = os.path.join("SDL2-2.28.5", "x86_64-w64-mingw32", "lib")
dest_lib = "lib"
if not os.path.exists(dest_lib):
    os.makedirs(dest_lib)

for f in os.listdir(src_lib):
    src_path = os.path.join(src_lib, f)
    if os.path.isfile(src_path):
        shutil.copy2(src_path, dest_lib)

print("Setting up runtime DLL...")
src_bin = os.path.join("SDL2-2.28.5", "x86_64-w64-mingw32", "bin")
dll_path = os.path.join(src_bin, "SDL2.dll")
if os.path.exists(dll_path):
    shutil.copy2(dll_path, "SDL2.dll")

print("Cleaning up...")
os.remove(zip_path)
shutil.rmtree("SDL2-2.28.5")
print("Done! You can now run 'make'.")
