class_name Savedata

const file_name = "user://savedata.lr"
var file = File.new()

# Datos internos
var tabla_actual = 0

# Datos principales
var objetivo : int = 0
var examen : int = 0
var puntos : int = 0
var ayudas : int = 0
var nivel : int = 0

# tablas [buenas, malas, completado]
var t2 = [0, 0, 0]
var t3 = [0, 0, 0]
var t4 = [0, 0, 0]
var t5 = [0, 0, 0]
var t6 = [0, 0, 0]
var t7 = [0, 0, 0]
var t8 = [0, 0, 0]
var t9 = [0, 0, 0]

# Retos [intentos, completado]
var r1 = [0, false]
var r2 = [0, false]
var r3 = [0, false]
var r4 = [0, false]

# Fin del juego
var endgame = false

func init_file() -> void: # Restart savedata file
	file.open(file_name, file.WRITE)
	
	if file.is_open():
		file.store_32(0) #Tabla Actual
		file.store_32(0) #Objetivo
		file.store_32(0) #Examen
		file.store_32(0) #Puntos
		file.store_32(3) #Ayudas
		file.store_32(0) #Nivel
		file.store_var([0, 0, 0]) #Tabla 2
		file.store_var([0, 0, 0]) #Tabla 3
		file.store_var([0, 0, 0]) #Tabla 4
		file.store_var([0, 0, 0]) #Tabla 5
		file.store_var([0, 0, 0]) #Tabla 6
		file.store_var([0, 0, 0]) #Tabla 7
		file.store_var([0, 0, 0]) #Tabla 8
		file.store_var([0, 0, 0]) #Tabla 9
		file.store_var([0, false]) #Reto 1
		file.store_var([0, false]) #Reto 2
		file.store_var([0, false]) #Reto 3
		file.store_var([0, false]) #Reto 4
		file.store_var(false) #endgame
		file.close()

func load_data() -> bool:
	file.open(file_name, file.READ)
	
	if file.is_open():
		self.tabla_actual = file.get_32() #Tabla Actual
		self.objetivo = file.get_32() #Objetivo
		self.examen = file.get_32() #Examen
		self.puntos = file.get_32() #Puntos
		self.ayudas = file.get_32() #Ayudas
		self.nivel = file.get_32() #Nivel
		self.t2 = file.get_var() #Tabla 2
		self.t3 = file.get_var() #Tabla 3
		self.t4 = file.get_var() #Tabla 4
		self.t5 = file.get_var() #Tabla 5
		self.t6 = file.get_var() #Tabla 6
		self.t7 = file.get_var() #Tabla 7
		self.t8 = file.get_var() #Tabla 8
		self.t9 = file.get_var() #Tabla 9
		self.r1 = file.get_var() #Reto 1
		self.r2 = file.get_var() #Reto 2
		self.r3 = file.get_var() #Reto 3
		self.r4 = file.get_var() #Reto 4
		self.endgame = file.get_var() #endgame
		
		file.close()
		return true
	
	else:
		init_file()
		if load_data() == false:
			return false
	
	return true

func save_data() -> void:
	file.open(file_name, file.WRITE)
	
	file.store_32(self.tabla_actual) #Tabla Actual
	file.store_32(self.objetivo) #Objetivo
	file.store_32(self.examen) #Examen
	file.store_32(self.puntos) #Puntos
	file.store_32(self.ayudas) #Ayudas
	file.store_32(self.nivel) #Nivel
	file.store_var(t2) #Tabla 2
	file.store_var(t3) #Tabla 3
	file.store_var(t4) #Tabla 4
	file.store_var(t5) #Tabla 5
	file.store_var(t6) #Tabla 6
	file.store_var(t7) #Tabla 7
	file.store_var(t8) #Tabla 8
	file.store_var(t9) #Tabla 9
	file.store_var(r1) #Reto 1
	file.store_var(r2) #Reto 2
	file.store_var(r3) #Reto 3
	file.store_var(r4) #Reto 4
	file.store_var(endgame) #endgame
	file.close()