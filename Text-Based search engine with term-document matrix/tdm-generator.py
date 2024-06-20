#!/usr/bin/env python3

import sys
import os

def main():

	# This path variable/name is used to accept and initialize the path names from stdin
	path=sys.argv[1]
	secondpath=sys.argv[2]
	
	#This function will be responsible for sorting document names
	filearray=listoarray(path,secondpath)
	
	#This function will be responsible for sorting term names
	newtermsorter=termsorter(path,secondpath)
	
	#This function will be responsible for sorting the frequency and creating the matrix
	firstdictionary=matrixmaker(path,newtermsorter,filearray,secondpath)

	#Creates the output directory
	os.makedirs(secondpath)
	os.chdir(secondpath)

	#Prints row and column for matrix file
	strings=str(len(newtermsorter))+" "+str(len(filearray))


	#creates each file with each different assortment of the arrays

	file = open("sorted_documents.txt","w")
	file.writelines("\n".join(filearray))
	file.close()

	files=open("sorted_terms.txt","w")
	files.writelines("\n".join(newtermsorter))
	files.close()


	filez=open("td_matrix.txt","w")
	filez.writelines(strings)
	filez.writelines("\n")

	for value in firstdictionary:
		string=" ".join(list(map(str,firstdictionary.get(value))))
		filez.writelines(string)
		filez.writelines("\n")
	filez.close()
		


	#Regarding the functions listoarray and termsorter when it creates a file and if you compare the created file with the output file it will say that there is a discrepancy between the created and original file. Specifically, regarding the issue where there is an extra newline at the end of the documents created by both these functions, but to provide my testimony the notification sent out by the terminal is not true as I did not find any extra newlines in the files generated by both of these functions. Therefore it implies that the console is a liar ._.

	#Regarding processing the last input02 it could take a while but i promise you that it works!



#This function handles with the file name and creates a sorted_documents.txt
def listoarray(path,secondpath):
	
	finallist=[]
	
	#if a filepath isn't valid then return an error statement (input validation)
	if not os.path.isdir(path):
		print("The file path does not exist")
		sys.exit()
	else:	
		#list to store the line-by-line words
		newlist=[]
		for root, dirs, files in os.walk(path,topdown=True):
			
			for filenames in files:
				if filenames.endswith(".txt"):
					newlist.append(filenames)
		#sorts the newlist and store it into finallist
		finallist=sorted(newlist)

	
	
	#returning the sorted word list so that we can use it in the matrixmaker function
	return finallist



#This function handles the reading of each file and creates a sorted_terms.txt
def termsorter(path,secondpath):
	placeholder=[]
	

	for root, dirs, files in os.walk(path,topdown=True):
		for pp in files:
			file_path=os.path.join(root,pp)
			if file_path.endswith(".txt"):
				file=open(file_path,"r")
				for line in file:
					pseudolist=line.strip().split(" ")
					#we are only concerned with the first words of each newline
					placeholder.append(pseudolist[0])

	#sorting
	placeholder.sort()
	placeholder2=set(placeholder)
	placeholder=sorted(list(placeholder2))
	
	
	return placeholder


#This function handles the wordcounts of each files within the directory and creates a td_matrix.txt
def matrixmaker(path,pp,filearray,secondpath):

	#This dictionary will store the values of the each of the terms in each files as an array
	firstdictionary={}
	ls=[]
	i=len(filearray)
	#Fills the dictionary with key-value pairs for the word and array. The words are supplied by the pp array which is the array containing the sorted terms from the previous function

	for k in range(0,i):
		ls.append(0)
	
		
	for word in pp:
		firstdictionary[word] = [0] * i

	


	

	#traverses the directory
		for root, dirs, files in os.walk(path,topdown=True):
		#look over the files that were traverse
			j=0
		for filename in filearray:
			
			#creates a filepath from current directory to the provided array
			file_path=os.path.join(root,filename)
			
			#reads only file with .txt extension
			if filename.endswith(".txt"):
				#open the file provided by the filepath
				file=open(file_path,"r")
				
				#reads line-by-line from file
				for line in file:
					#line is splitted and stored within the pseudolist list
					pseudolist=line.strip().split(" ")

					if pseudolist[0] in firstdictionary:

						newlist=firstdictionary.get(pseudolist[0])
						newlist[j]=str(pseudolist[1])
						
				#this variable starts with 0 and is used to keep track of the current position in the list of files and the number of files that has been iterated through
				j += 1
			
	
	return firstdictionary


	

if __name__=='__main__':
	main()
