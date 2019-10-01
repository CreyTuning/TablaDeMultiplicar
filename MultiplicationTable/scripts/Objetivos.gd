class_name Objetivos

var savedata : Savedata = Savedata.new()
var language : Language = Language.new()
var puede_ascender : bool = false
var ascendio : bool = false
var puede_evaluar : bool = false

var objetivos = [
	#Objetivo 0
	["¡Bienvenido! puedes hacer del mundo un lugar mejor si dedicas parte de tu tiempo en aprender y utilizar lo aprendido creando cosas maravillosas.",
	"Consigue 600 Puntos",
	"Consigue en tabla 2 (5 Completados)"],
	
	#Objetivo 1
	["¡Buen trabajo!",
	"Asciende (en el menú de estado)"],

	#Objetivo 2
	["La propiedad conmutativa te permite multiplicar en el orden que desees, el resultado será el mismo.",
	"Completa el reto"],

	#Objetivo 3
	["La matemática es la ciencia que permite contar, calcular, medir o describir las formas de las cosas.",
	"Consigue 1200 Puntos",
	"Consigue en tabla 3 (3 Completados)",
	"Consigue en tabla 4 (50 Correctos)"],

	#Objetivo 4
	["¡Buen trabajo!",
	"Asciende (en el menú de estado)"],

	#Objetivo 5
	["Puedes pausar la información inicial del reto si mantienes presionado.",
	"Completa el reto"],

	#Objetivo 6
	["El lenguaje algebraico convierte algunos problemas en situaciones fáciles de resolver.",
	"Consigue 2500 Puntos",
	"Consigue en tabla 4 (12 Completados)",
	"Consigue en tabla 5 (50 Correctos)"],

	#Objetivo 7
	["¡Buen trabajo!",
	"Asciende (en el menú de estado)"],

	#Objetivo 8
	["Cuando resuelves un problema o investigas, debes explicar claramente los pasos que has seguido y las soluciones que has encontrado.",
	"Completa el reto"],

	#Objetivo 9
	["La multiplicación consiste en sumar un número tantas veces como indique otro...",
	"Consigue 5000 Puntos",
	"Consigue en tabla 5 (15 Completados)",
	"Consigue en tabla 6 (50 Correctos)",
	"Consigue en tabla 7 (7 Completados)",
	"Consigue en tabla 8 (5 Completados)"],

	#Objetivo 10
	["¡Buen trabajo!",
	"Asciende (en el menú de estado)"],

	#Objetivo 11
	["Paciencia y practica es la clave.",
	"Completa el reto"],

	#Objetivo 12
	["Grandes dificultades a grandes vencedores.",
	"Supera los 4 Retos"],
	
	#Objetivo 13
	["¡Buen trabajo!",
	"Completa el reto final"]
]

var objectives = [
	#Objetivo 0
	["Welcome! you can make the world a better place if you dedicate part of your time in learning and using what you learned by creating wonderful things.",
	"Get 600 Score",
	"Get in table 2 (5 Completed)"],
	
	#Objetivo 1
	["Good work!",
	"Ascend (in status section)"],

	#Objetivo 2
	["The commutative property allows you to multiply in the order you want, the result will be the same.",
	"Complete the challenge"],

	#Objetivo 3
	["Mathematics is the science that allows us to count, calculate, measure or describe the shapes of things.",
	"Get 1200 Score",
	"Get in table 3 (3 Completed)",
	"Get in table 4 (50 Hits)"],

	#Objetivo 4
	["Good work!",
	"Ascend (in status section)"],

	#Objetivo 5
	["You can pause the initial challenge information if you keep pressing.",
	"Complete the challenge"],

	#Objetivo 6
	["The algebraic language turns some problems into easy situations to solve.",
	"Get 2500 Score",
	"Get in table 4 (12 Completed)",
	"Get in table 5 (50 Hits)"],

	#Objetivo 7
	["Good work!",
	"Ascend (in status section)"],

	#Objetivo 8
	["When you solve a problem or investigate, you must cearly explain the steps you have taken and the solutions you have found.",
	"Complete the challenge"],

	#Objetivo 9
	["Multiplication consists in adding a number as many times as indicated by another...",
	"Get 5000 Score",
	"Get in table 5 (15 Completed)",
	"Get in table 6 (50 Hits)",
	"Get in table 7 (7 Completed)",
	"Get in table 8 (5 Completed)"],

	#Objetivo 10
	["Good work!",
	"Ascend (in status section)"],

	#Objetivo 11
	["Patience and practice is the key.",
	"Complete the challenge"],

	#Objetivo 12
	["Great difficulties to great winners.",
	"Complete the four challenges"],
	
	#Objetivo 13
	["Good work!",
	"Complete the final challenge"]
]

func get_objetivo():
	language.load_data()
	
	if language.language == 'es':
		return objetivos[savedata.objetivo]
	elif language.language == 'en':
		return objectives[savedata.objetivo]

func check_objetivo() -> void:
	savedata.load_data()
	
	match savedata.objetivo:
		0:
			puede_ascender = false
			
			if savedata.puntos >= 600 and savedata.t2[2] >= 5:
				savedata.objetivo = 1
				puede_ascender = true
		1:
			if savedata.puntos < 600 or savedata.t2[2] < 5:
				savedata.objetivo = 0
			else:
				puede_ascender = true
				
				if ascendio == true:
					savedata.puntos -= 600
					savedata.objetivo = 2
					savedata.nivel = 1
					ascendio = false
					puede_ascender = false
		2:
			puede_evaluar = true
			
			if savedata.examen == 1:
				savedata.puntos += 250
				puede_evaluar = false
				savedata.objetivo = 3
		3:
			if savedata.puntos >= 1200 and savedata.t3[2] >= 3 and savedata.t4[0] >= 50:
				savedata.objetivo = 4
		4:
			if savedata.puntos < 1200 or savedata.t3[2] < 3 or savedata.t4[0] < 50:
				savedata.objetivo = 3
				puede_ascender = false
			else:
				puede_ascender = true
				
				if ascendio == true:
					savedata.objetivo = 5
					savedata.nivel = 2
					savedata.puntos -= 1200
					puede_ascender = false
					ascendio = false
		5:
			puede_evaluar = true
			
			if savedata.examen == 2:
				savedata.puntos += 450
				puede_evaluar = false
				savedata.objetivo = 6
		6:
			if savedata.puntos >= 2500 and savedata.t4[2] >= 12 and savedata.t5[0] >= 50:
				savedata.objetivo = 7
		7:
			if savedata.puntos < 2500 or savedata.t4[2] < 12 or savedata.t5[0] < 50:
				savedata.objetivo = 6
				puede_ascender = false
			else:
				puede_ascender = true
				
				if ascendio == true:
					savedata.objetivo = 8
					savedata.nivel = 3
					savedata.puntos -= 1200
					puede_ascender = false
					ascendio = false
		8:
			puede_evaluar = true
			
			if savedata.examen == 3:
				savedata.puntos += 600
				puede_evaluar = false
				savedata.objetivo = 9
		9:
			if savedata.puntos >= 5000 and savedata.t6[0] >= 50 and savedata.t7[2] >= 7 and savedata.t8[2] >= 5:
				savedata.objetivo = 10
		10:
			if savedata.puntos < 5000 or savedata.t6[0] < 50 or savedata.t7[2] < 7 or savedata.t8[2] < 5:
				savedata.objetivo = 9
				puede_ascender = false
			else:
				puede_ascender = true
				
				if ascendio == true:
					savedata.objetivo = 11
					savedata.nivel = 4
					savedata.puntos -= 5000
					puede_ascender = false
					ascendio = false
		11:
			puede_evaluar = true
			
			if savedata.examen == 4:
				puede_evaluar = false
				savedata.objetivo = 12
		12:
			if savedata.r1[1] == true and savedata.r2[1] == true and savedata.r3[1] == true and savedata.r4[1] == true:
				savedata.objetivo = 13
		13:
			if savedata.r1[1] == false or savedata.r2[1] == false or savedata.r3[1] == false or savedata.r4[1] == false:
				savedata.objetivo = 12
			else:
				puede_evaluar = true
				
	savedata.save_data()