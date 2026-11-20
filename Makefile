all:
	g++ main.cpp LogAnalyzer.cpp -o loganalyzer

clean:
	rm -f loganalyzer
