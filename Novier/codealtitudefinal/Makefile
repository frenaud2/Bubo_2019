CXX=g++
CXXFLAGS=-std=c++11
LDFLAGS=
LLIB=lib/
LDEFS=
SOURCES=

all: lib
	$(CXX) Tubdd.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o Tubdd

	$(CXX) listerEnregistrements.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o listerEnregistrements.cgi

	$(CXX) listerLampadairesProches.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o lampProches.cgi

	$(CXX) lireGPS.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o gps.cgi

	$(CXX) modifier.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o modifier.cgi

	$(CXX) supprimer.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o supprimer.cgi

	$(CXX) viderTable.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o viderTable.cgi

	$(CXX) listes.cpp $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o listes.cgi



lib: $(LLIB)Enregistrement.o $(LLIB)Logger.o  $(LLIB)Horodatage.o  $(LLIB)Lampadaire.o  $(LLIB)Ampoule.o  $(LLIB)Galerie.o  $(LLIB)GPS.o  $(LLIB)Geolocalisation.o  $(LLIB)BDD.o  $(LLIB)Collecteur.o  $(LLIB)Luxmetre.o


$(LLIB)Enregistrement.o: $(SOURCES)Enregistrement.cpp  $(LDEFS)Enregistrement.h
	$(CXX) -c $(SOURCES)Enregistrement.cpp -o $@ $(CXXFLAGS)

$(LLIB)Logger.o: $(SOURCES)Logger.cpp  $(LDEFS)Logger.h
	$(CXX) -c $(SOURCES)Logger.cpp -o $@ $(CXXFLAGS)

$(LLIB)Horodatage.o: $(SOURCES)Horodatage.cpp	 $(LDEFS)Horodatage.h
	$(CXX) -c $(SOURCES)Horodatage.cpp -o $@ $(CXXFLAGS)

$(LLIB)Lampadaire.o: $(SOURCES)Lampadaire.cpp   $(LDEFS)Lampadaire.h
	$(CXX) -c $(SOURCES)Lampadaire.cpp -o $@ $(CXXFLAGS)

$(LLIB)Ampoule.o: $(SOURCES)Ampoule.cpp  $(LDEFS)Ampoule.h
	$(CXX) -c $(SOURCES)Ampoule.cpp -o $@ $(CXXFLAGS)

$(LLIB)Galerie.o: $(SOURCES)Galerie.cpp  $(LDEFS)Galerie.h
	$(CXX) -c $(SOURCES)Galerie.cpp -o $@ $(CXXFLAGS)

$(LLIB)GPS.o: $(SOURCES)GPS.cpp  $(LDEFS)GPS.h
	$(CXX) -c $(SOURCES)GPS.cpp -o $@ $(CXXFLAGS)

$(LLIB)Geolocalisation.o: $(SOURCES)Geolocalisation.cpp  $(LDEFS)Geolocalisation.h
	$(CXX) -c $(SOURCES)Geolocalisation.cpp -o $@ $(CXXFLAGS)

$(LLIB)BDD.o: $(SOURCES)BDD.cpp  $(LDEFS)BDD.h
	$(CXX) -c $(SOURCES)BDD.cpp -o $@ $(CXXFLAGS)

$(LLIB)Luxmetre.o: $(SOURCES)Luxmetre.cpp  $(LDEFS)Luxmetre.h
	$(CXX) -c $(SOURCES)Luxmetre.cpp -o $@ $(CXXFLAGS)

$(LLIB)Collecteur.o: $(SOURCES)Collecteur.cpp  $(LDEFS)Collecteur.h
	$(CXX) -c $(SOURCES)Collecteur.cpp -o $@ $(CXXFLAGS)



clean:
	rm -rf *.o
mrproper:
	clean rm -rf enregistrer.cgi
