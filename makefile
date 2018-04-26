onda.png : datos.txt graph.py
	python graph.py
datos.txt : onda.cpp
	c++ onda.cpp -o econda
	./econda > datos.txt
