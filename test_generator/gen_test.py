#!/usr/bin/python

from __future__ import print_function
from sys import argv
from string import printable
from random import random, randrange, choice, randint
from multiprocessing import Process, JoinableQueue
from shutil import copyfileobj
from os import remove

def random_word(max, set):
	return (''.join(choice(set) for i in range(randrange(1, max))))

def tuan(q, filename_tmp):
	print("Starting worker. writing in {}".format(filename_tmp))
	with open(filename_tmp, "w") as f:
		while (True):
			item = q.get()
			if item is None:
				break
			print(item, file=f)
			item = None
			q.task_done()
		q.task_done()
		print("Killing Worker")


def main(max):
	rand_word = ''
	filename_tmp = "file_tmp.txt"
	final_file = "dataset.txt"
	q = JoinableQueue()
	tuan_worker = Process(target=tuan, args=(q, filename_tmp,))
	tuan_worker.start() # start tuan.
	alphanum = printable[0:62]
	alpha = printable[10:62]
	with open(final_file, "w") as f:
		print("Writing in {}".format(final_file))
		for x in range(max):
			rand_word = random_word(64, alpha)
			if randint(0, 100) <= 50:
				q.put(rand_word)
			else:
				q.put(random_word(64, alphanum))
			print(rand_word, random_word(64, alphanum),
					sep='\n', file=f)
		else:
			q.put(None)
			q.join()
			tuan_worker.join() # kill tuan.
			print(file=f)
			with open(filename_tmp, "r") as f2:
				copyfileobj(f2, f)
			print("Removing {}".format(filename_tmp))
			remove(filename_tmp)
	print("Work is done. =D")

if __name__ == "__main__":
	if(len(argv) == 2):
		print("Generating database entry :{}".format(argv[1]))
		main(int(argv[1]))
	else:
		print("Usage : gen_test int_value")

