all:
	gcc writeserver.c -o write.out
	gcc readserver.c -o read.out
	gcc fifoeavesdropper.c -o eaves.out
	echo "compiled"
