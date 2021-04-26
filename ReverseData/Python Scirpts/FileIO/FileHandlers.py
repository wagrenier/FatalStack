import json

# define global values
p_ext_lbl = 0x00000000
p_cd_dat = 0x002F30B8
file_dat_tbl = [0x002b6b80, 0x002b6c28, 0x002b6cd0, 0x002b6d70, 0x002b6dd8]
cd_dat_tbl = {}
with open('cd_dat_tbl.json') as f:
    cd_dat_tbl = json.load(f)



def cddatIsCmpFile(param_1):
    return (p_cd_dat + param_1 * 0xc) & 1


def GetFileData(param_1, param_2):
    return (file_dat_tbl + param_1 * 4) + param_2 * 4


def GetAlignUp(param_1, param_2):
    return ((param_1 + ~(-1 << (param_2 & 0x1f))) >> (param_2 & 0x1f)) << (param_2 & 0x1f)


def GetFileSize(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc + 4), 4)


def GetFileSectorSize(param_1):
    iVar1 = GetFileSize(param_1)
    return iVar1 + 0x7ff >> 0xb


def GetFileStartSector(param_1):
    return (p_cd_dat + param_1 * 0xc) >> 2


def FurnCtlCheckFileType(param_1):
    iVar1 = 0x0
    uVar2 = 0xffffffff

    if param_1 != 0x0:
        iVar1 = param_1
        uVar2 = 0
        #if ((((iVar1 != 0x627a70) && (uVar2 = 1, iVar1 != 0x666870)) && (uVar2 = 2, iVar1 != 0x1050)) && (uVar2 = 4, (param_1[1] | param_1[2] | param_1[3]) != 0)):
        #    uVar2 = 0xffffffff

    return uVar2


if __name__ == '__main__':
    files = [
        0xC34,
        0xC33,
        0x742
    ]

    for file in files:
        file_size = GetFileSize(file)
        var1 = GetAlignUp(file_size, 6)
        print(f'FileID:{hex(file)},File size:{hex(cd_dat_tbl[hex(file_size)])},FileStartSector:{hex(GetFileStartSector(file))},IsCmpFile:{cddatIsCmpFile(file) == 1}')
