class board:
	matrix = []

	def __init__(self):
		for i in range(0, 6):
			row = []
			for j in range(0, 7):
				row.append(0)
			self.matrix.append(row)


	def __str__(self):
		s = ""
		for i in range(0,6):
			for j in range(0, 7):
				s += str(self.matrix[5-i][j])
			s += '\n'
		return s

	def winner(self, player):
		# horrizontals
		for i in range(0, 6):
			run = 0
			for j in range(0, 7):
				if self.matrix[i][j] is player:
					run+=1
				else:
					run = 0
				if run is 4:
					return True

		#verticals
		for j in range(0, 7):
			run = 0
			for i in range(0, 6):
				if self.matrix[i][j] is player:
					run+=1
				else:
					run = 0
				if run is 4:
					return True


		#diagonals
		for x in range(4):
			for y in range(3, 6):
				if self.matrix[x][y] == player and self.matrix[x+1][y-1] == player and self.matrix[x+2][y-2] == player and self.matrix[x+3][y-3] == player:
					return True

		# check \ diagonal spaces
		for x in range(4):
			for y in range(3):
				if self.matrix[x][y] == player and self.matrix[x+1][y+1] == player and self.matrix[x+2][y+2] == player and self.matrix[x+3][y+3] == player:
					return True

		return False

	def winner_check(self):
		if self.winner(1):
			print("winner 1")
		elif self.winner(2):
			print("winner 2")

	def drop(self, col, player):
		if self.matrix[5][col] is not 0:
			return False
		for i in range(0, 6):
			if self.matrix[i][col] is 0:
				self.matrix[i][col] = player
				self.winner_check()
				return True
