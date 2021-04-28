# Import statements
from FileGlobalParameters import *


def GetAlignUp(param_1, param_2):
    return ((param_1 + ~(-1 << (param_2 & 0x1f))) >> (param_2 & 0x1f)) << (param_2 & 0x1f)


def cddatIsCmpFile(file_index):
    return cd_dat_tbl[hex(p_cd_dat + file_index * 0xc)] & 1


def cddatIsFile(file_index):
    file_status = cd_dat_tbl[hex(p_cd_dat + file_index * 0xc)] & 0b00000011
    if file_status == 0b00:
        return FileStatus.NO_FILE
    elif file_status == 0b10:
        return FileStatus.FILE_NOT_COMPRESSED
    elif file_status == 0b11:
        return FileStatus.FILE_COMPRESSED

    return FileStatus.NO_FILE


def GetFileData(param_1, param_2):
    return (file_dat_tbl + param_1 * 4) + param_2 * 4


def GetFile(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc), 4)


def GetFileSize(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc + 4), 4)


def GetFileCmpSize(file_index):
    return GetAlignUp((p_cd_dat + file_index * 0xc + 8), 4)


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


def GetFileEndAddress(file_start_addr, file_size):
    print()


"""
For each file:
* 4 byte - LBA
* 4 byte - unpack file size
* 4 byte - file size in archive
"""


def ExtractFile(file_index):
    file = cd_dat_tbl[hex(GetFile(file_index))]
    file_status = cddatIsFile(file_index)
    file_size = cd_dat_tbl[hex(GetFileSize(file_index))]
    file_size_cmp = cd_dat_tbl[hex(GetFileCmpSize(file_index))]
    file_bd_addr = Compute_IMG_BIN_File_Address(file)
    file_end = file_bd_addr + file_size_cmp

    if DEBUG:
        print(
            f'FileID:{hex(file_index)},FileSize:{float(file_size)},CmpSize:{float(file_size_cmp)},IsCmpFile:'
            f'{cddatIsFile(file_index)},FileLBA:{hex(file_bd_addr)},FileEnd:{hex(file_end)}'
        )

    return \
        {
            'FileID': file_index,
            'File': file,
            'FileStatus': file_status,
            'FileBDAddr': file_bd_addr,
            'FileBDEndAddr': file_end,
            'FileSize': file_size,
            'FileSizeCmp': file_size_cmp
        }


def extract_addr(json):
    try:
        return json['FileBDAddr']
    except KeyError:
        return 0


def BuildFileDb():
    files_id = range(0, project_file_num - 1)
    file_db = []

    for curr_file in files_id:
        extracted_file = ExtractFile(curr_file)

        file_db.append(extracted_file)

    file_db.sort(key=extract_addr)

    #for my_file in file_db:
        #print(my_file)


def Compute_IMG_BIN_File_Address(file):
    file_lba = (file >> 2) * sector_size
    return file_lba


if __name__ == '__main__':
    BuildFileDb()
