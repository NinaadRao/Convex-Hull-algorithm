import matplotlib.pyplot as plt
import numpy
from matplotlib.widgets import Button
import subprocess

def plot_graph(x_pts,y_pts,results_x,results_y,title,range_of_values,savef):
	plt.scatter(x_pts,y_pts,color='red',s=5)
	plt.plot(results_x,results_y,linewidth=1)
	plt.title(title)
	plt.xlabel('X')
	plt.ylabel('Y')
	plt.xlim(0,range_of_values)
	plt.ylim(0,range_of_values)
	plt.savefig(savef)
	plt.show()

yes=1
while(yes):
	print('Press:\n\t1:User generated input\n\t2:Test on the given input')
	flag=int(input())
	if(flag==1):
		x_pts = []
		y_pts = []

		fig, ax = plt.subplots()
		#ay=plt.subplot(111)
		ax.set_xlim([0, 10])
		ax.set_ylim([0, 10])

		line, = ax.plot(x_pts, y_pts, marker="o")

		def onpick(event):
		    m_x, m_y = event.x, event.y
		    x, y = ax.transData.inverted().transform([m_x, m_y])

		    x_pts.append(x)
		    y_pts.append(y)
		    #line.set_xdata(x_pts)
		    #line.set_ydata(y_pts)
		    plt.scatter(x_pts,y_pts,color='red',s=5)
		    fig.canvas.draw()

		fig.canvas.mpl_connect('button_press_event', onpick)
		def handle_close(evt):
		    print('Closed Figure!')
		fig.canvas.mpl_connect('close_event', handle_close)
		plt.title('Coordinates for Convex hull(Close the window once input is given!!)')
		plt.show()
		pts=[(x_pts[i],y_pts[i]) for i in range(len(x_pts))]
		fp=open('user_input.txt','w')
		fp.write(str(len(pts)))
		fp.write('\n')
		for i in pts:
			fp.write(str(i[0]))
			fp.write(', ')
			fp.write(str(i[1]))
			fp.write('\n')
		fp.close()
		if(len(x_pts)<3):
			print('Not possible to construct')
			print('Press 0 for exiting and 1 to continue')
			yes=int(input())
			continue
			
		
		subprocess.call('g++ divide_and_conquer.cpp -o divide_and_conquer.out',shell=True)
		subprocess.call('./divide_and_conquer.out < user_input.txt > user_output.txt',shell=True)
		print('Divide and Conquer completed')
		fp=open('user_output.txt','r')
		count=0
		N=len(x_pts)
		print('N',N)
		g=fp.readlines()
		g=[i.strip() for i in g]
		K=int(g[0])
		print(g)
		g.pop(0)
		results=[tuple(map(float,g[i].split(','))) for i in range(K)]
		print(results)
		results_x=[results[i][0] for i in range(K)]
		results_x.append(results_x[0])
		results_y=[results[i][1] for i in range(K)]
		results_y.append(results_y[0])
		time_taken=float(g[-1])
		print(results_x)
		print(results_y)
		plot_graph(x_pts,y_pts,results_x,results_y,'Result for Convex Hull',15,'ui.png')


		


	elif(flag==2):

		print('Convex Hull: Divide and Conquer Started')
		subprocess.call('g++ divide_and_conquer_analysis.cpp -o dc.out',shell=True)
		subprocess.call('./dc.out',shell=True)
		print('Convex Hull: Divide and Conquer Completed')


		print('Convex Hull: Quickhull Started')
		subprocess.call('g++ quickhull.cpp -o quickhull.out',shell=True)
		subprocess.call('./quickhull.out',shell=True)
		print('Convex Hull: Quickhull Completed')

		print('Convex Hull: Jarvis March Started')
		subprocess.call('g++ jarvis_march.cpp -o jarvis_march.out',shell=True)
		subprocess.call('./jarvis_march.out',shell=True)
		print('Convex Hull: Jarvis March Completed')

		print('Convex Hull: Graham Scan Started')
		subprocess.call('g++ graham_scan.cpp -o graham_scan.out',shell=True)
		subprocess.call('./graham_scan.out',shell=True)
		print('Convex Hull: Graham Scan Completed')

		# Add your method here and since the output is the same for all the methods, we can just take the time component from the rest of the files
		len_100=[]
		len_1000=[]
		len_10000=[]
		output_x_100=[]
		output_x_1000=[]
		output_x_10000=[]
		output_y_100=[]
		output_y_1000=[]
		output_y_10000=[]
		output_len_100=[]
		output_len_1000=[]
		output_len_10000=[]
		x_pts_100=[]
		x_pts_1000=[]
		x_pts_10000=[]
		y_pts_100=[]
		y_pts_1000=[]
		y_pts_10000=[]
		path1='inputs_100/'
		path2='inputs_1000/'
		path3='inputs_10000/'
		path4='outputs_100/'
		path5='outputs_1000/'
		path6='outputs_10000/'
		
		for i in range(16):
			fp=open(path1+'input'+str(i+1)+'.txt')
			g=fp.readlines()
			len_100.append(int(g[0]))
			g.pop(0)
			if(len_100[-1]<3):
				print('Cannot construct')
			results=[tuple(map(float,g[i].split(','))) for i in range(len_100[-1])]
			results_x=[results[i][0] for i in range(len_100[-1])]
			results_y=[results[i][1] for i in range(len_100[-1])]
			x_pts_100.append(results_x)
			y_pts_100.append(results_y)
			fp.close()
			fp=open(path4+'output_dc_convexhull'+str(i+1)+'.txt')
			g=fp.readlines()
			output_len_100.append(int(g[0]))
			g.pop(0)
			results=[tuple(map(float,g[i].split(','))) for i in range(output_len_100[-1])]
			results_x=[results[i][0] for i in range(output_len_100[-1])]
			results_x.append(results_x[0])
			
			results_y=[results[i][1] for i in range(output_len_100[-1])]
			results_y.append(results_y[0])
			
			output_x_100.append(results_x)
			output_y_100.append(results_y)
			fp.close()
		print("Length is\n")
		print(len_100)
			
		for i in range(16):
			fp=open(path2+'input'+str(i+1)+'.txt')
			g=fp.readlines()
			len_1000.append(int(g[0]))
			g.pop(0)

			if(len_1000[-1]<3):
				print('Cannot construct')
			results=[tuple(map(float,g[i].split(','))) for i in range(len_1000[-1])]
			results_x=[results[i][0] for i in range(len_1000[-1])]
			results_y=[results[i][1] for i in range(len_1000[-1])]
			x_pts_1000.append(results_x)
			y_pts_1000.append(results_y)
			fp.close()
			fp=open(path5+'output_dc_convexhull'+str(i+1)+'.txt')
			g=fp.readlines()
			output_len_1000.append(int(g[0]))
			g.pop(0)
			results=[tuple(map(float,g[i].split(','))) for i in range(output_len_1000[-1])]
			results_x=[results[i][0] for i in range(output_len_1000[-1])]
			results_x.append(results_x[0])
			
			results_y=[results[i][1] for i in range(output_len_1000[-1])]
			results_y.append(results_y[0])
			
			output_x_1000.append(results_x)
			output_y_1000.append(results_y)
			fp.close()



		for i in range(16):
			fp=open(path3+'input'+str(i+1)+'.txt')
			g=fp.readlines()
			len_10000.append(int(g[0]))
			g.pop(0)

			if(len_10000[-1]<3):
				print('Cannot construct')
			results=[tuple(map(float,g[i].split(','))) for i in range(len_10000[-1])]
			results_x=[results[i][0] for i in range(len_10000[-1])]

			results_y=[results[i][1] for i in range(len_10000[-1])]
			x_pts_10000.append(results_x)
			y_pts_10000.append(results_y)
			fp.close()

			fp=open(path6+'output_dc_convexhull'+str(i+1)+'.txt')
			g=fp.readlines()
			output_len_10000.append(int(g[0]))
			g.pop(0)
			results=[tuple(map(float,g[i].split(','))) for i in range(output_len_10000[-1])]
			results_x=[results[i][0] for i in range(output_len_10000[-1])]
			results_x.append(results_x[0])
			results_y=[results[i][1] for i in range(output_len_10000[-1])]
			results_y.append(results_y[0])
			# print(results_x,results_y)
			output_x_10000.append(results_x)
			output_y_10000.append(results_y)
			fp.close()
		for i in range(16):
		 	plot_graph(x_pts_100[i],y_pts_100[i],output_x_100[i],output_y_100[i],'Input Size: '+str(len_100[i]),150,'100:'+str(len_100[i])+'.png')
		for i in range(16):
		 	plot_graph(x_pts_1000[i],y_pts_1000[i],output_x_1000[i],output_y_1000[i],'Input Size: '+str(len_1000[i]),1200,'1000:'+str(len_1000[i])+'.png')
		for i in range(16):
			plot_graph(x_pts_10000[i],y_pts_10000[i],output_x_10000[i],output_y_10000[i],'Input Size: '+str(len_10000[i]),10200,'10000:'+str(len_10000[i])+'.png')
		
		output_lists=list()
		for i in range(3):
			output_lists.append(list())
			for j in range(4):
				output_lists[i].append(list())
		
		names_list = ["dc","gs","jm","qh"]

		for i in range(16):
			for j in range(len(names_list)):
				
				fp1=open(path4+'output_'+names_list[j]+'_convexhull'+str(i+1)+'.txt')
				fp2=open(path5+'output_'+names_list[j]+'_convexhull'+str(i+1)+'.txt')
				fp3=open(path6+'output_'+names_list[j]+'_convexhull'+str(i+1)+'.txt')

				g1=fp1.readlines()
				g2=fp2.readlines()
				g3=fp3.readlines()

				output_lists[0][j].append(float(g1[-1]))
				output_lists[1][j].append(float(g2[-1]))
				output_lists[2][j].append(float(g3[-1]))


		#print(output_lists)		

		yaxis_list=list()
		for i in range(len(len_100)):
			yaxis_list.append(i)	
		
		plt.plot(yaxis_list,output_lists[0][0],label="Divide and Conquer",color='black')
		plt.plot(yaxis_list,output_lists[0][1],label="Graham Scan",color='green')
		plt.plot(yaxis_list,output_lists[0][2],label="Jarvis March",color='red')
		plt.plot(yaxis_list,output_lists[0][3],label="Quickhull",color='blue')
		plt.title('Range of 100 numbers')
		plt.ylim((0, 1.05))
		plt.legend()
		plt.savefig('100.png')

		plt.show()


		plt.plot(yaxis_list,output_lists[1][0],label="Divide and Conquer",color='black')
		plt.plot(yaxis_list,output_lists[0][1],label="Graham Scan",color='green')
		plt.plot(yaxis_list,output_lists[1][2],label="Jarvis March",color='red')
		plt.plot(yaxis_list,output_lists[1][3],label="Quickhull",color='blue')
		plt.title('Range of 1000 numbers')
		plt.ylim((0, 1.05))
		plt.legend()
		plt.savefig('1000.png')
		plt.show()



		plt.plot(yaxis_list,output_lists[2][0],label="Divide and Conquer",color='black')
		plt.plot(yaxis_list,output_lists[0][1],label="Graham Scan",color='green')
		plt.plot(yaxis_list,output_lists[2][2],label="Jarvis March",color='red')
		plt.plot(yaxis_list,output_lists[2][3],label="Quickhull",color='blue')
		plt.title('Range of 10000 numbers')
		plt.ylim((0, 1.05))
		plt.legend()
		plt.savefig('10000.png')
		plt.show()

		print("Len 100 is ",output_len_100)
		print("Len 1000 is ",output_len_1000)
		print("Len 10000 is ",output_len_10000)



		plt.plot(yaxis_list,output_len_100,label="Range of 100",color='black')
		#plt.plot(yaxis_list,output_lists[0][1],label="Graham Scan",color='green')
		plt.plot(yaxis_list,output_len_1000,label="Range of 1000",color='red')
		plt.plot(yaxis_list,output_len_10000,label="Range of 10000",color='blue')
		plt.title('Number of vertices of convex hull')
		
		plt.legend()
		plt.savefig('vertices.png')
		plt.show()

	print('Press 0 for exiting and 1 to continue')
	yes=int(input())