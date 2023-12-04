Main: Main.o Election.o Candidate.o Report.o CSVReader.o Party.o
	g++ -o main Main.o Election.o Candidate.o Report.o CSVReader.o Party.o

Main.o: Main.cpp Election.h Candidate.h Report.h CSVReader.h Party.h
	g++ -c -o Main.o Main.cpp

Election.o: Election.cpp Election.h Candidate.h Party.h
	g++ -c -o Election.o Election.cpp

Candidate.o: Candidate.cpp Candidate.h Election.h
	g++ -c -o Candidate.o Candidate.cpp

Report.o: Report.cpp Report.h Candidate.h Party.h Election.h
	g++ -c -o Report.o Report.cpp

CSVReader.o: CSVReader.cpp CSVReader.h
	g++ -c -o CSVReader.o CSVReader.cpp

Party.o: Party.cpp Party.h Candidate.h
	g++ -c -o Party.o Party.cpp

clean:
	rm main
	rm *.o

run:
	@./main
