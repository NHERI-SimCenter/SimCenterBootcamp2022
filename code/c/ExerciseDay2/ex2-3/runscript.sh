#!/usr/bin/env bash

if [ -x ./Exercise2-3 ]
then
	./Exercise2-3 5.0 > list.csv
fi

if [ -x ${HOME}/bin/python3 ]
then
	${HOME}/bin/python3 plotter.py
elif [ -x ${HOME}/bin/python ]
then
	${HOME}/bin/python plotter.py
elif [ -x /usr/local/bin/python3 ]
then
	/usr/local/bin/python3 plotter.py
elif [ -x /usr/bin/python3 ]
then
	/usr/bin/python3 plotter.py
elif [ -x /usr/local/bin/python ]
then
	/usr/local/bin/python plotter.py
elif [ -x /usr/bin/python ]
then
	/usr/bin/python plotter.py
fi


