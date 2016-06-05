use v5.22;
use warnings;
use utf8;

use Mojo::Util qw/slurp/;

my @header_files = `find ./ -name "*.h"`;

for (@header_files) {
  my $filename = $_;
  chomp $filename;
  my $contents = slurp $filename;
  my $header_flag = make_header_flag($filename);
  unless ($contents =~ /$header_flag/) {
    $contents = "
#ifndef $header_flag
#define $header_flag

$contents

#endif
";
    my_write($filename, $contents);
  }
}

sub make_header_flag {
  my $file = shift;
  my $header_flag = uc $file;
  $header_flag =~ s/\./_/g;
  $header_flag =~ s/_\/SOURCE\///g;
  $header_flag =~ s/SCENE\/START\//START_/g;
  $header_flag =~ s/SCENE\/GAME\//GAME_/g;
  $header_flag =~ s/SCENE\///g;
  return $header_flag;
}

sub my_write {
  my ($filename, $contents) = @_;
  open(my $fh, '>', $filename) or die 'uups';
  $fh->print($contents);
  $fh->close();
}
