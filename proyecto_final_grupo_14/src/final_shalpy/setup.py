from setuptools import setup

package_name = 'final_shalpy'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='juanespadi',
    maintainer_email='j.padillat@uniandes.edu.co',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'shalpy_teleop = final_shalpy.shalpy_teleop:main',
            'turtle_bot_interface = final_shalpy.turtle_bot_interface:main',
            'turtle_bot_player = final_shalpy.turtle_bot_player:main'
        ],
    },
)
