# Import statements
import json

# Define global values
# 2048 bytes
sector_size = 0x800

# Number of files in the cddat
project_file_num = 0x106B
p_cd_dat = 0x002F30B8
p_ext_lbl = 0x002FF5C0
file_dat_tbl = [0x002b6b80, 0x002b6c28, 0x002b6cd0, 0x002b6d70, 0x002b6dd8]
cd_dat_tbl = {}
file_ext_dat = {}

# Reading values from json file
with open('cd_dat_tbl.json') as f:
    cd_dat_tbl = json.load(f)

with open('file_ext_tbl.json') as f:
    file_ext_dat = json.load(f)
