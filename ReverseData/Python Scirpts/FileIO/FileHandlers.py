# Import statements
from FileGlobalParameters import *


def GetAlignUp(param_1, param_2):
    return ((param_1 + ~(-1 << (param_2 & 0x1f))) >> (param_2 & 0x1f)) << (param_2 & 0x1f)


def cddatIsCmpFile(file_index):
    print(hex(p_cd_dat + file_index * 0xc))
    return cd_dat_tbl[hex(p_cd_dat + file_index * 0xc)] & 1


def GetFileCmpSize(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc + 8), 4)


def GetFileData(param_1, param_2):
    return (file_dat_tbl + param_1 * 4) + param_2 * 4


def GetFileSize(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc + 4), 4)


def GetFileSectorSize(file_index):
    iVar1 = GetFileSize(file_index)
    return iVar1 + 0x7ff >> 0xb


def GetFileStartSector(file_index):
    return (p_cd_dat + file_index * 0xc) >> 2


def FurnCtlCheckFileType(param_1):
    iVar1 = 0x0
    uVar2 = 0xffffffff

    if param_1 != 0x0:
        iVar1 = param_1
        uVar2 = 0

        if iVar1 != 0x627a70:
            uVar2 = 1
            if iVar1 != 0x666870:
                uVar2 = 2
                if iVar1 != 0x1050:
                    uVar2 = 4
                    if (param_1[1] | param_1[2] | param_1[3]) != 0:
                        uVar2 = 0xffffffff

    return uVar2


def buildFileDb():
    print()


def compute_IMG_BIN_File_Address(file_index):
    print()


if __name__ == '__main__':
    files_id = range(0, project_file_num)

    for file in files_id:
        file_size = GetFileSize(file)
        var1 = GetAlignUp(file_size, 6)
        print(f'FileID:{hex(file)},File size:{hex(cd_dat_tbl[hex(file_size)])},FileStartSector:{hex(GetFileStartSector(file))},IsCmpFile:{cddatIsCmpFile(file) == 1},CmpSize:{hex(cd_dat_tbl[hex(GetFileCmpSize(file))])}')
        #,FileData:{hex(GetFileData(file))}
