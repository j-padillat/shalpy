from setuptools import setup

package_name = 'cameraraspy'

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
    maintainer='jp',
    maintainer_email='j.rincono@uniandes.edu.co',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
	'console_scripts': [
		'sent_image = cameraraspy.sent_image:main',
		'rec_image = cameraraspy.rec_image:main',
	],
	},
)
