#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

void FindFile(const std::wstring &directory)
{
    std::wstring tmp = directory + L"\\*";
    WIN32_FIND_DATAW file;
    HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);
    if (search_handle != INVALID_HANDLE_VALUE)
    {
        std::vector<std::wstring> directories;

        do
        {
            if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
                    continue;
            }

            tmp = directory + L"\\" + std::wstring(file.cFileName);
            std::wcout << tmp << std::endl;

            if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                directories.push_back(tmp);
        }
        while (FindNextFileW(search_handle, &file));

        FindClose(search_handle);

        for(std::vector<std::wstring>::iterator iter = directories.begin(), end = directories.end(); iter != end; ++iter)
            FindFile(*iter);
    }
}

int main()
{
    FindFile(L"C:");
    return 0;
}
