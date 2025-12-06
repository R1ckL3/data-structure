import os
import json

# Automatically use the directory where this script is located
ROOT_PATH = os.path.dirname(os.path.abspath(__file__))
OUTPUT_FILE = "structure.json"

def scan_directory(path):
    tree = {"name": os.path.basename(path), "type": "directory", "children": []}

    try:
        for entry in os.scandir(path):
            if entry.is_dir():
                tree["children"].append(scan_directory(entry.path))
            else:
                tree["children"].append({
                    "name": entry.name,
                    "type": "file"
                })
    except PermissionError:
        pass

    return tree

def save_structure_to_json(root_path, output_file):
    structure = scan_directory(root_path)
    with open(output_file, "w", encoding="utf-8") as f:
        json.dump(structure, f, indent=4)

if __name__ == "__main__":
    save_structure_to_json(ROOT_PATH, OUTPUT_FILE)
    print(f"Saved directory structure to {OUTPUT_FILE}")