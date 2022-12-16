def get_outcome_score(opponent, player):
    if opponent == player:
        return 3
    if opponent == "ROCK":
        if player == "SCISSORS":
            return 0
        if player == "PAPER":
            return 6
    if opponent == "SCISSORS":
        if player == "PAPER":
            return 0
        if player == "ROCK":
            return 6
    if opponent == "PAPER":
        if player == "ROCK":
            return 0
        if player == "SCISSORS":
            return 6

def rock_paper_scissors(strategy_guide):
    shape = {"X": "ROCK", "Y": "PAPER", "Z": "SCISSORS", "A": "ROCK", "B": "PAPER", "C": "SCISSORS"}
    points = {"ROCK": 1, "PAPER": 2, "SCISSORS": 3}
    score = 0
    for game in strategy_guide:
        player, opponent = shape[game[2]], shape[game[0]]
        score += points[player] + get_outcome_score(opponent, player)
    return score
        
def rock_paper_scissors_2(strategy_guide):
    opponent_choice = {"A": "ROCK", "B": "PAPER", "C": "SCISSORS"}
    player_choice = { "ROCK": {"X": "SCISSORS", "Y": "ROCK", "Z": "PAPER"},
    "PAPER": {"X": "ROCK", "Y": "PAPER", "Z": "SCISSORS"},
    "SCISSORS": {"X": "PAPER", "Y": "SCISSORS", "Z": "ROCK"}}
    points = {"ROCK": 1, "PAPER": 2, "SCISSORS": 3}
    score = 0
    for game in strategy_guide:
        opponent = opponent_choice[game[0]]
        player = player_choice[opponent][game[2]]
        score += points[player] + get_outcome_score(opponent, player)
    return score

input_file = open("input_files/day2_input.txt", "r")
strategy_guide = input_file.read().split('\n')
input_file.close()
print(rock_paper_scissors(strategy_guide))
print(rock_paper_scissors_2(strategy_guide))