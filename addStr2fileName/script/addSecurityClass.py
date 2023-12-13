import os
import glob

def addSecCls(fileList, path, str):
    if os.path.isdir(path):
        search_path = os.path.join(path, '*')
        file_list = glob.glob(search_path)
        for file in file_list:
            if not str in file:
                directory = os.path.dirname(file)
                old_name = os.path.basename(file)
                new_name = str + old_name
                old_path = os.path.join(directory, old_name)
                new_path = os.path.join(directory, new_name)
                os.rename(old_path, new_path)
            else:
                continue
        new_list = glob.glob(search_path)
        return new_list