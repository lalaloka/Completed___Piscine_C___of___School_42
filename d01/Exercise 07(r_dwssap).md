# day 01 Exercise 07

 - Напишите командную строку, которая отображает вывод cat/etc/passwd удаляя комментарии, отображает каждую вторую строку, начиная со второй, инвертируя каждый логин и сортируя в обратном порядке, сохраняя только логины включенными между FT_LINE1 и FT_LINE2 включительно, разделенных символом «,» (без кавычек) и заканчивающихся символом «.».


---
---
---


Создадим файл скрипта:

	touch r_dwssap.sh




И запишем в него это:

```
#!/bin/sh
cat /etc/passwd | grep -v "^#" | sed '1!n;d' | sed -e 's/:.*//' | rev | sort -r | sed -n "$FT_LINE1 $FT_LINE2 p" | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/, /g' | sed 's/$/./' | tr -d '\n'
```




На выводе должно быть примерно это:
```
yxorp, ydobon, xumbsu, tiktr, sys, swen, subegassem, semag, rehctapsid-hceeps, putes-laitini-emong, pukcab, pl, nomead, evloser-dmetsys, eulcoeg, eslup, droloc, ddiuu, cri, anldinim.
```



> cat /etc/passwd 	- выводим текст
> 
> grep -v "^#"	 	- убираем комментарии
> 
> sed '1!n;d' 		- отбражаем каждую вторую строку, начиная со второй(1,3,5,7)
> 
> sed -e 's/:.*//'	- убираем лишнее справа
> 
> rev			- реверсирование каждого логина: Команда будет переворачивать слова и предложения задом наперед
> 
> sotr -r			- сортировать в обратном порядке
> 
> sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/, /g' - заменяем переносы строки на запятые с пробелом
> 
> sed 's/$/./'		- ставим в конце точку
> tr -d '\n' 		- убираем переносы строк


---
---
---



### ОРИГИНАЛ:

```
#!/bin/sh
cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | sed 's/:\(.*\)//g' | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/\(.*\), /\1./' | tr -d '\n'
```




И УРЕЗАНАЯ:

```
#!/bin/sh
cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | sed 's/:\(.*\)//g' | rev | sort -r |  tr '\n' ' ' | sed 's/ /, /g' | sed 's/\(.*\), /\1./' | tr -d '\n'
```




На выводе должно быть примерно это:
```
yxorp, ydobon, xumbsu, tiktr, sys, swen, subegassem, semag, rehctapsid-hceeps, putes-laitini-emong, pukcab, pl, nomead, evloser-dmetsys, eulcoeg, eslup, droloc, ddiuu, cri, anldinim.
```



---
---
---



### ИЛИ ЭТО:



```
#!/bin/sh
cat /etc/passwd | sed -n "$FT_LINE1 $FT_LINE2 p" | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e 's/:.*//g' | tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" "," | sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//' 's/$/./'
```


На выводе должно быть примерно это:
```
yxorp, ydobon, xumbsu, tsil, tpa_, toor, tiktr, sys, swen, subegassem, stang, semag, repleh-kp-spuc, rehctapsid-hceeps, qsamsnd, putes-laitini-emong, pukcab, pl, pilph, pcuu, nomead, nib, nam, mdg, liam, krowten-dmetsys, ihava, golsys, evloser-dmetsys, eulcoeg, eslup, eikooooc, droloc, dpiotua-ihava, denas, ddiuu, cri, cnys, atad-www, anldinim.
```



> cat /etc/passwd 	- выводим текст
> 
> sed -e 's/#.*//' 	- убираем комментарии 
> 
> -e 's/[ ^I]*$//' 	- убираем комментарии и все ненужное
> 
> -e '/^$/ d' -e 's/:.*//g' - убираем все остальное оставляя только список 

> каждая вторая строка, начиная со второй, реверсирование каждого логина, отсортировано в обратном алфавитном порядке.
> 
> | tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" ","  
> 
> | sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//'




---
---
---



## Документация.

Google.com :)
