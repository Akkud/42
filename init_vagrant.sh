mkdir -p /Volumes/Storage/goinfre/$USER/vagrant

echo 'export VAGRANT_HOME=/Volumes/Storage/goinfre/$USER/vagrant' >> ~/.zshrc
cd ~/goinfre
cat > Vagrantfile << EOM
Vagrant.configure("2") do |config|
	config.vm.box = "debian/stretch64"
	config.vm.synced_folder ".", "/git"
	config.vm.provider "virtualbox" do |vb|
		vb.gui = true
		vb.memory = "2048"
		vb.customize ["modifyvm", :id, "--vram", "12"]
	end
end
EOM

vagrant plugin install vagrant-vbguest

vagrant up

vagrant vbguest

vagrant ssh
