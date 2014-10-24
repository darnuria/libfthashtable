#!/usr/bin/python

from sys import stdin

def main():
	searchmod = False
	table = {}
	tag = ''

	for line in stdin:
		if line == '\n':
			searchmod = True
		elif searchmod == False:
			if tag == '':
				tag = line[:-1]
				continue
			else:
				table[tag] = line[:-1]
				tag = ''
		elif searchmod == True:
			search = line[:-1]
			if search in table :
				print("mot-clef :[{}] {}".format(search, table[search]))
			else:
				print("mot-clef[{}] not found.".format(search))
		elif line == '\n':
			break

if __name__ == "__main__":
	main()
