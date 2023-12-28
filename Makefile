default:
	g++ -o main.exe main.cpp src/MonteCarlo.cpp src/BlackScholes.cpp
	g++ -o main_plot.exe main_plot.cpp src/MonteCarlo.cpp 