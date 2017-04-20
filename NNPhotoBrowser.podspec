
Pod::Spec.new do |s|

  s.name         = "NNPhotoBrowser"
  s.version      = "0.0.2"
  s.summary      = "summary NNPhotoBrowser"
  s.description  = "A short description of NNPhotoBrowser."
  s.homepage     = "https://github.com/yesencai/NNPhotos"
  s.license          = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "yesencai" => "yesencai@163.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/yesencai/NNPhotos.git", :tag => "#{s.version}" }
  s.source_files  = "NNPhotoBrowser/**/*.{h,m}"
  s.resource  = 'NNPhotoBrowser/PYPhotosView.bundle'
  s.requires_arc = true

end
