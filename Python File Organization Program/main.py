import os
import shutil
import re


def main():
    #Foldernames
    Foldernames=["ImageFolder","DocumentFolder","AudioFolder","ProgrammingFolder","Epubs","Other"]


    #File types
    File_Types=[[".img",".jpg",".svg",".jpeg",".png",".gif",".bmp", "Screenshot"],
                [".docx", ".pdf", ".pptx", ".xlsx", ".txt", ".rtf", ".odt", ".csv"],
                [".mp3", ".mp4"],
                [".py", ".c", ".cpp", ".html", ".css", ".java", ".js", ".cs", ".ruby"],
                [".epub"]
                ]

    #Obtaining the location of the filepath to be organized
    location=input("Please Enter the Location of Where You Would Like to Organize your files!")
    os.chdir(location)


    #Check if Folders in 'Foldernames' already exists in the current directory
    for i in range(len(Foldernames)+1):
        temp1=os.path.join(location,Foldernames[i])
        os.makedirs(temp1,exist_ok=True)


    for i in range(len(Foldernames)):
        DirectoryContent = os.listdir(location)  # Listing Current Files that exists in the Folder
        for j in File_Types[i]:
            for k in DirectoryContent:
                if re.search(j,k):
                    shutil.move(k,Foldernames[i])
                    DirectoryContent.remove(k)
                else:
                    continue



    return "The Sorting is Complete!";


if __name__ == "__main__":
    main()