build:
	g++ main.cpp utils.cpp player.cpp team.cpp Match.cpp Node.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty
