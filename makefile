all: makebnum

makebnum: makebint
	bnum/make library

makebint:
	bint/make library
