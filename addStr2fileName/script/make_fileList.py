import os
import glob

def mk_fList(path):
    if os.path.isdir(path):
        search_path = os.path.join(path, '*')
        file_list = glob.glob(search_path)
        return file_list