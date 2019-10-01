class_name Multiplicando

var respondidos = []

func get_number() -> int:
	randomize()
	
	if respondidos.size() == 11:
		respondidos.append(-1)
		return -1
	
	var num : int = randi() % 11
	
	while num in respondidos:
		num = randi() % 11
	
	respondidos.append(num)
	return num

func get_current() -> int:
	return respondidos[respondidos.size() - 1]

func completed() -> bool:
	if respondidos.size() >= 12:
		return true
	else:
		return false