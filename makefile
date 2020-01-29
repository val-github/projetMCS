all : exe1 exe2

exe1 :
	gcc pokerSrv.c -o srv

exe2 :
	gcc pokerClt.c -o clt
