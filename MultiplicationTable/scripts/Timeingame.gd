class_name Timeingame

const file_name = "user://timeingame.lr"
var file = File.new()


var timeingame = [0, 0, 0, 0]


func init_file() -> void: # Restart savedata file
	file.open(file_name, file.WRITE)
	
	if file.is_open():
		file.store_var([0, 0, 0, 0]) #Tiempo de juego
		file.close()

func load_data() -> bool:
	file.open(file_name, file.READ)
	
	if file.is_open():
		self.timeingame = file.get_var() #Tiempo de juego
		
		file.close()
		return true
		
	else:
		init_file()
		if load_data() == false:
			return false
			
	return true

func save_data() -> void:
	file.open(file_name, file.WRITE)
	file.store_var(timeingame) #Tiempo de juego
	file.close()


func add_second():
	load_data()
	timeingame[3] += 1
	
	if timeingame[3] > 59:
		timeingame[3] = 0
		timeingame[2] += 1
		
		if timeingame[2] > 59:
			timeingame[2] = 0
			timeingame[1] += 1
			
			if timeingame[1] > 23:
				timeingame[1] = 0
				timeingame[0] += 1
	save_data()


func get_time():
	load_data()
	return [timeingame[0], timeingame[1], timeingame[2], timeingame[3]]


func show():
	print(timeingame[0], ":", timeingame[1], ":", timeingame[2], ":", timeingame[3])