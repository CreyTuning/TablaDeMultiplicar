class_name Language

const file_name = "user://language.lr"
var file = File.new()


var language = "en"


func init_file() -> void: # Restart savedata file
	file.open(file_name, file.WRITE)
	
	if file.is_open():
		file.store_var("en") #Lenguaje
		file.close()

func load_data() -> bool:
	file.open(file_name, file.READ)
	
	if file.is_open():
		self.language = file.get_var() #Lenguaje
		
		file.close()
		return true
		
	else:
		init_file()
		if load_data() == false:
			return false
			
	return true


func save_data() -> void:
	file.open(file_name, file.WRITE)
	file.store_var(language) #Lenguaje
	file.close()


func get_language():
	load_data()
	return language