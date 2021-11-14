import folium as fol

map = fol.Map(
    location=[45.5236, -122.6750], zoom_start=12,
    tiles='Stamen Terrain',
)

fol.Marker(
    location=[45.5236, -122.6750],
    popup='Portland, OR',
    icon=fol.Icon(color='green')
).add_to(map)

map.save('map.html')
