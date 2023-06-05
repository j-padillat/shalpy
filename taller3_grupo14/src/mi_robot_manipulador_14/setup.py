from setuptools import setup

package_name = 'mi_robot_manipulador_14'

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
            'robot_manipulator_teleop = mi_robot_manipulador_14.robot_manipulator_teleop:main'
        ],
    },
)
