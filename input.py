import tkinter as tk
import numpy as np
from tkinter import ttk

num_stages = 3
colors = np.array(["green", "magenta", "yellow", "blue"])

class ShapeDrawer:
    def __init__(self, root):
        self.root = root
        self.root.title("Аэродинамика ракеты-носителя. Исходные данные")

        self.scale_factor = 20.0  # Коэффициент масштабирования

        # Semi-ellipse inputs
        self.semi_ellipse_width_label = ttk.Label(root, text="Диаметр ГО:")
        self.semi_ellipse_width_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")
        self.semi_ellipse_width_entry = ttk.Entry(root)
        self.semi_ellipse_width_entry.grid(row=0, column=1, padx=5, pady=5)
        self.semi_ellipse_width_entry.insert(0, "3.7")

        self.semi_ellipse_height_label = ttk.Label(root, text="Высота ГО:")
        self.semi_ellipse_height_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")
        self.semi_ellipse_height_entry = ttk.Entry(root)
        self.semi_ellipse_height_entry.grid(row=1, column=1, padx=5, pady=5)
        self.semi_ellipse_height_entry.insert(0, "7.0")

        # Trapezoid inputs
        self.trapezoid_labels = []
        self.trapezoid_entries = []
        
        a1 = np.array([[3.7, 3.7, 7.0], [3.7, 4.1, 2.0], [4.1, 4.1, 14.0]])
        
        for i in range(num_stages):
            top_base_label = ttk.Label(root, text=f"Элемент {i+1}. Верхний диаметр:")
            top_base_label.grid(row=2+i*3, column=0, padx=5, pady=5, sticky="w")
            top_base_entry = ttk.Entry(root)
            top_base_entry.grid(row=2+i*3, column=1, padx=5, pady=5)
            top_base_entry.insert(0, str(a1[i,0]))

            bottom_base_label = ttk.Label(root, text=f"Элемент {i+1}. Нижний диаметр:")
            bottom_base_label.grid(row=3+i*3, column=0, padx=5, pady=5, sticky="w")
            bottom_base_entry = ttk.Entry(root)
            bottom_base_entry.grid(row=3+i*3, column=1, padx=5, pady=5)
            bottom_base_entry.insert(0, str(a1[i,1]))

            height_label = ttk.Label(root, text=f"Элемент {i+1}. Высота:")
            height_label.grid(row=4+i*3, column=0, padx=5, pady=5, sticky="w")
            height_entry = ttk.Entry(root)
            height_entry.grid(row=4+i*3, column=1, padx=5, pady=5)
            height_entry.insert(0, str(a1[i,2]))

            self.trapezoid_labels.extend([top_base_label, bottom_base_label, height_label])
            self.trapezoid_entries.extend([top_base_entry, bottom_base_entry, height_entry])

        self.canvas = tk.Canvas(root, width=600, height=800, bg="white")
        self.canvas.grid(row=0, column=2, rowspan=15, padx=5, pady=5)

        # Bind events
        self.semi_ellipse_width_entry.bind("<KeyRelease>", self.draw_shapes)
        self.semi_ellipse_height_entry.bind("<KeyRelease>", self.draw_shapes)
        for entry in self.trapezoid_entries:
            entry.bind("<KeyRelease>", self.draw_shapes)

        self.draw_shapes(None)  # Initial draw with default values

    def draw_shapes(self, event):
        self.canvas.delete("all")
        try:
            # Draw semi-ellipse
            semi_ellipse_width = float(self.semi_ellipse_width_entry.get())/2 * self.scale_factor
            semi_ellipse_height = float(self.semi_ellipse_height_entry.get()) * self.scale_factor
            self.canvas.create_arc(300 - semi_ellipse_width, 50, 300 + semi_ellipse_width, 50 + 2 * semi_ellipse_height, start=0, extent=180, outline="black", fill="black")

            # Draw trapezoids
            y_offset = 50 + semi_ellipse_height
            for i in range(num_stages):
                top_base = float(self.trapezoid_entries[i*3].get()) * self.scale_factor
                bottom_base = float(self.trapezoid_entries[i*3+1].get()) * self.scale_factor
                height = float(self.trapezoid_entries[i*3+2].get()) * self.scale_factor
                col = "grey"
                if (top_base < bottom_base):
                    col = "orange"
                self.canvas.create_polygon(300 - top_base / 2, y_offset, 300 + top_base / 2, y_offset, 300 + bottom_base / 2, y_offset + height, 300 - bottom_base / 2, y_offset + height, outline="black", fill=col)
                y_offset += height
        except ValueError:
            pass

if __name__ == "__main__":
    root = tk.Tk()
    app = ShapeDrawer(root)
    root.mainloop()
