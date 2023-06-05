import tkinter as tk
import random
from tkinter import messagebox
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class GraphApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Shalpy-Manipulador")
        self.configure(bg="orange") 
        self.x_points = []
        self.y_points = []
        self.figure = Figure(figsize=(6, 6), dpi=100)
        self.ax = self.figure.add_subplot(111)
        self.ax.set_xlabel('X')
        self.ax.set_ylabel('Y')
        self.ax.set_title('Recorrido End Effector')
        self.ax.plot([], [], 'go-')
        
        self.canvas = FigureCanvasTkAgg(self.figure, master=self)
        self.canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        self.save_button = tk.Button(self, text="Guardar", command=self.GuardarRecorrido)
        self.save_button.pack(side=tk.BOTTOM)
        self.agregarPunto()
        
    def GuardarRecorrido(self):
        file_path = tk.filedialog.asksaveasfilename(defaultextension=".png",
                                                    filetypes=(("PNG files", "*.png"), ("All files", "*.*")))
        if file_path:
            self.figure.savefig(file_path)
            messagebox.showinfo("Guardar", "La gráfica ha sido guardada correctamente.")
            
    def agregarPunto(self):
        x = random.randint(0, 10)
        y = random.randint(0, 10)
        self.add_point(x, y)
        self.after(10, self.agregarPunto)
        
    def add_point(self, x, y):
        self.x_points.append(x)
        self.y_points.append(y)
        self.ax.plot(self.x_points, self.y_points, 'go-') 
        self.canvas.draw()


def main():
    app = GraphApp()
    app.mainloop()


if __name__ == '__main__':
    main()
