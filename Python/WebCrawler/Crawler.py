import urllib2 
html=urllib2.urlopen("https://www.youtube.com/").read()
#print(html)

i,n=0,len(html)
tags={'tags':1}
while i<n:
	i=html.find('<',i,n)
	# j,k=html.find(' ',i+1,n),html.find('>',i+1,n)
	# if j!=-1 and k !=-1:
	# 	j=min(j,k)
	# elif k!=-1:
	# 	j=k
	if i==-1:
		break
	j=i
	while j<n and (html[j]!=' ' and html[j]!='>'):
		j +=1;
	s=html[i:j]+'>'
	if tags.has_key(s):
		tags[s]=tags[s]+1
	else:
		tags[s]=1
	i=j					
print(len(tags))