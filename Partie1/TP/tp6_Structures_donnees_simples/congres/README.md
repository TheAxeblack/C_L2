# Organisation d'un congrès

On souhaite gérer une base de données d'inscription pour l'organisation d'un congrès qui dure une journée. Les organisateurs proposent aux participants de s'inscrire pour des repas, ainsi que l'hébergement en hôtel.

Un participant peut s'inscrire indépendament aux 2 repas proposés : déjeuner (15€) et/ou dîner (35€) ou aucun. Il n'est pas obligé de prendre un hôtel. S'il en prend un, il peut choisir parmis deux types : 2 étoiles (75€) ou 3 étoiles (100€). Un participant peut venir accompagné de conjoint. Dans ce cas, la réservation d'hôtel est identique mais lorsqu'un repas est sélectionné, il faut en compter deux.

+ Définir un nouveau type `participant` qui inclut, son nom, son prénom, ainsi que toute autre informations nécessaires à son inscription selon les critères définis ci-dessus. On privilégiera une structure contenant un nombre minimal de champs.
+ Définir un nouveau type `tabPart` qui est un tableau de 100 éléments de type `participant`.
+ Définir une fonction `nb2etoiles` qui, pour un argument de type `tabPart` donné, affiche le nom et le prénom des personnes ayant choisi de réserver un hôtel 2 étoiles.
+ Définir une fonction `nbDej` qui, pour un argument de type `tabPart` donné, affiche le nombre de personnes ayant choisi de réserver le déjeuner.