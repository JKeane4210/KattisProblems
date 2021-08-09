line = input()
words = line.split(" ")
team_1 = []
team_2 = []

count = input()
count = int(count)

players = []
for i in range(count):
	player = input()
	players.append(player)

ind = 0
goTo1 = True

while len(players) > 0:
	ind = (ind + len(words) - 1) % len(players)
	removal = players[ind]
	players.remove(removal)
	if goTo1:
		team_1.append(removal)
		goTo1 = False
	else:
		team_2.append(removal)
		goTo1 = True

print(len(team_1))
for player in team_1:
	print(player)
print(len(team_2))
for player in team_2:
	print(player)